#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#ifndef _STRINGTABLE_H_
#include "core/stringTable.h"
#endif

// Template use: struct MyDictEntryClass : public DictEntryBase<MyDictEntryClass>
template <typename TEntrySubclass>
struct DictEntryBase {
    StringTableEntry name;
    TEntrySubclass* nextEntry;

    DictEntryBase() = delete;

    // Constructor required for Dictionary<T>
    DictEntryBase(StringTableEntry name)
        : name(name)
        , nextEntry(NULL)
    { }
};

extern S64 HashPointer(StringTableEntry ptr);

template <typename TEntry, S32 ST_INIT_SIZE = 15>
class Dictionary
{
protected:
    struct HashTableData
    {
        Dictionary* owner;
        S32 size;
        S32 count;
        TEntry** data;
    };

    HashTableData* hashTable;
    HashTableData localHashTable;
public:
    typedef TEntry Entry;

    TEntry* lookup(StringTableEntry name) const
    {
        TEntry* walk = hashTable->data[HashPointer(name) % hashTable->size];
        while (walk)
        {
            if (walk->name == name)
                return walk;
            else
                walk = walk->nextEntry;
        }

        return NULL;
    }

    TEntry* add(StringTableEntry name)
    {
        TEntry* walk = hashTable->data[HashPointer(name) % hashTable->size];
        while (walk)
        {
            if (walk->name == name)
                return walk;
            else
                walk = walk->nextEntry;
        }
        TEntry* ret;
        hashTable->count++;

        if (hashTable->count > hashTable->size * 2)
        {
            TEntry head(NULL), * walk;
            S32 i;
            walk = &head;
            walk->nextEntry = 0;
            for (i = 0; i < hashTable->size; i++) {
                while (walk->nextEntry) {
                    walk = walk->nextEntry;
                }
                walk->nextEntry = hashTable->data[i];
            }
            delete[] hashTable->data;
            hashTable->size = hashTable->size * 4 - 1;
            hashTable->data = new TEntry * [hashTable->size];
            for (i = 0; i < hashTable->size; i++)
                hashTable->data[i] = NULL;
            walk = head.nextEntry;
            while (walk)
            {
                TEntry* temp = walk->nextEntry;
                S32 idx = HashPointer(walk->name) % hashTable->size;
                walk->nextEntry = hashTable->data[idx];
                hashTable->data[idx] = walk;
                walk = temp;
            }
        }

        ret = new TEntry(name);
        S32 idx = HashPointer(name) % hashTable->size;
        ret->nextEntry = hashTable->data[idx];
        hashTable->data[idx] = ret;
        return ret;
    }

    void setState(Dictionary* ref = NULL)
    {
        if (ref)
        {
            hashTable = ref->hashTable;
        }
        else
        {
            // Avoid redundant allocation, the tables are not refcounted
            // anyway so use-after-free was just as much a risk before...
            hashTable = &localHashTable;
            hashTable->owner = this;
            hashTable->count = 0;
            hashTable->size = ST_INIT_SIZE;
            hashTable->data = new TEntry * [hashTable->size];

            for (S32 i = 0; i < hashTable->size; i++)
                hashTable->data[i] = NULL;
        }
    }

    // remove() is a stable remove (will not reorder entries on remove)
    void remove(TEntry* ent)
    {
        TEntry** walk = &hashTable->data[HashPointer(ent->name) % hashTable->size];
        while (*walk != ent)
            walk = &((*walk)->nextEntry);

        *walk = (ent->nextEntry);
        delete ent;
        hashTable->count--;
    }

    void reset()
    {
        S32 i;
        TEntry* walk, * temp;

        for (i = 0; i < hashTable->size; i++)
        {
            walk = hashTable->data[i];
            while (walk)
            {
                temp = walk->nextEntry;
                delete walk;
                walk = temp;
            }
            hashTable->data[i] = NULL;
        }
        hashTable->size = ST_INIT_SIZE;
        hashTable->count = 0;
    }

    Dictionary()
        : hashTable(NULL),
        localHashTable{}
    {
    }

    Dictionary(Dictionary* ref)
        : hashTable(NULL),
        localHashTable{}
    {
        setState(ref);
    }

    ~Dictionary()
    {
        if (hashTable && (hashTable->owner == this))
        {
            reset();
            delete[] hashTable->data;
        }
    }

    bool isAllocated() const { return !!hashTable; }
};

#endif
