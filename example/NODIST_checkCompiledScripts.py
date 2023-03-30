#------------------------------------------------
#   TORQUE GAME ENGINE CS/DSO PARITY CHECKER
#------------------------------------------------

import glob
from os import path

cs_files    = glob.glob("**/*.cs", recursive=True)      + glob.glob("**/*.gui", recursive=True)
dso_files   = glob.glob("**/*.cs.dso", recursive=True)  + glob.glob("**/*.gui.dso", recursive=True)

for i in range(len(cs_files)):
    cs_files[i] = cs_files[i].lower().removesuffix(".cs").removesuffix(".gui")

for i in range(len(dso_files)):
    dso_files[i] = dso_files[i].lower().removesuffix(".cs.dso").removesuffix(".gui.dso")

if len(cs_files + dso_files) == 0:
    print("No script files to check.")
    exit(0)

# Do set check
cs_set  = set(cs_files)
dso_set = set(dso_files)
if cs_set == dso_set:
    print("All script files are compiled.")
    exit(0)
else:
    uncomp = sorted(cs_set.difference(dso_set))
    print(str(len(uncomp)) + " uncompiled script files found:")
    for s in uncomp:
        print("-  " + s)
    exit(1)
