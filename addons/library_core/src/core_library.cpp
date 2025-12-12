#include "core_library.h"

#include <godot_cpp/classes/dir_access.hpp>

void CoreLibrary::_bind_methods() {
    ClassDB::bind_method(D_METHOD("scan_project", "root_path"), &CoreLibrary::scan_project, DEFVAL("res://"));
}

CoreLibrary::CoreLibrary() {
}

CoreLibrary::~CoreLibrary() {
}

TypedArray<String> CoreLibrary::scan_project(String root_path) {
    found_assets.clear();
    _scan_recursive(root_path);
    return found_assets;
}

void CoreLibrary::_scan_recursive(String path) {
    Ref<DirAccess> dir = DirAccess::open(path);
    if (dir.is_valid()) {
        dir->list_dir_begin();
        String file_name = dir->get_next();
        while (file_name != "") {
            if (dir->current_is_dir()) {
                if (file_name != "." && file_name != ".." && file_name != ".godot") {
                    _scan_recursive(path + "/" + file_name);
                }
            } else {
                if (file_name.ends_with(".tres")) {
                    found_assets.append(path + "/" + file_name);
                }
            }
            file_name = dir->get_next();
        }
    }
}
