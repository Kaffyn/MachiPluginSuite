import os
import subprocess
import sys

def build_plugins():
    root_dir = os.path.dirname(os.path.abspath(__file__))
    addons_dir = os.path.join(root_dir, 'addons')
    log_file_path = os.path.join(root_dir, 'build.log')
    
    # Ensure addons directory exists
    if not os.path.exists(addons_dir):
        print(f"Error: 'addons' directory not found at {addons_dir}")
        return

    # Open log file in write mode with UTF-8 encoding
    with open(log_file_path, 'w', encoding='utf-8') as log_file:
        log_file.write("Build Log for Machi Plugin Suite\n")
        log_file.write("===================================\n\n")

        # Iterate over all directories in addons
        for item in os.listdir(addons_dir):
            plugin_path = os.path.join(addons_dir, item)
            
            if os.path.isdir(plugin_path):
                sconstruct_path = os.path.join(plugin_path, 'SConstruct')
                
                # Check if it's a SCons project
                if os.path.exists(sconstruct_path):
                    print(f"Building plugin: {item}...")
                    log_file.write(f"\n--- Building Plugin: {item} ---\n")
                    log_file.flush()
                    
                    try:
                        # Run scons command
                        # We build for the current platform (likely windows)
                        # redirecting stdout and stderr to the log file
                        # using shell=True to pick up scons from path
                        
                        # Note: scons usually defaults to platform=host, target=template_debug
                        # You can add arguments if needed, e.g., ['scons', 'target=template_release']
                        # Using python -m SCons to avoid PATH issues
                        command = [sys.executable, '-m', 'SCons', '-j4'] # -j4 for parallel build
                        
                        # Capture output
                        result = subprocess.run(
                            command,
                            cwd=plugin_path,
                            stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT,
                            text=True,
                            encoding='cp1252', # Windows console uses CP1252
                            errors='replace',
                            check=False, # Don't raise exception on failure, just log it
                            shell=True
                        )
                        
                        log_file.write(result.stdout)
                        
                        if result.returncode == 0:
                            print(f"  [SUCCESS] {item}")
                            log_file.write(f"\n[SUCCESS] Build finished for {item}\n")
                        else:
                            print(f"  [FAILURE] {item} (Exit Code: {result.returncode})")
                            log_file.write(f"\n[FAILURE] Build failed for {item} (Exit Code: {result.returncode})\n")
                            
                    except Exception as e:
                        print(f"  [ERROR] Exception while building {item}: {e}")
                        log_file.write(f"\n[ERROR] Exception while building {item}: {e}\n")
                    
                    log_file.flush()
                else:
                   # Not a scons project (maybe just a gdscript plugin or unfinished)
                   pass

    print(f"\nBuild process completed. Logs saved to: {log_file_path}")

if __name__ == "__main__":
    build_plugins()
