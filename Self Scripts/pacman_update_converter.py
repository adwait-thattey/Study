# converts
# pkg old_version -> new_version
# to
# sudo pacman -S --noconfirm pkg

#!/bin/python3

import sys
append_line = "sudo pacman -S --noconfirm "
if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise AttributeError("filename containing packages update list is required as 1st argument")
        
    
    file_name = sys.argv[1]
    f = open(file_name, mode="r")
    lines = f.readlines()
    f.close()
    package_names = list()
    for l in lines:
        names = l.split()
        pkg_name = append_line + names[0]
        package_names.append(pkg_name)
    
    out_file = sys.argv[2] if len(sys.argv)>2 else "/tmp/modified_update_list.txt"
    print(f"Out file: {out_file} ")
    f2 = open(out_file, mode="w")
    f2.write("\n".join(package_names))
    f2.close()
    print(f"Written {len(package_names)} packages ")