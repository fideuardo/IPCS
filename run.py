import os
import shutil
import sys
import subprocess
import argparse

def build_project(build_dir="build"):
    """Build the project using CMake with parallel compilation."""
    try:
        print(f"Configuring and building the project in {build_dir}...")
        command = f"cmake -B {build_dir} && cmake --build {build_dir} -j4" # Added -j4
        result = subprocess.run(command, shell=True, capture_output=True, text=True, check=True)
        print(result.stdout)
        print("Build completed successfully.")

    except subprocess.CalledProcessError as e:
        print(f"Error during build: {e}")
        print(e.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Unexpected error during build: {e}")
        sys.exit(1)

def clean_project(build_dir="build"):
    """Clean the build directory."""
    try:
        if os.path.exists(build_dir):
            print(f"Removing build directory {build_dir}...")
            shutil.rmtree(build_dir)
            print("Cleanup completed.")
        else:
            print(f"Build directory {build_dir} does not exist.")
    except Exception as e:
        print(f"Error during cleanup: {e}")
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description="CMake project build script.")
    parser.add_argument("command", choices=["build", "clean"], help="Command to execute (build or clean).")
    parser.add_argument("--build-dir", default="build", help="Build directory.")

    args = parser.parse_args()

    if args.command == "build":
        if not os.path.exists("CMakeLists.txt"):
            print("Error: CMakeLists.txt not found in the current directory.")
            sys.exit(1)
        build_project(args.build_dir)
    elif args.command == "clean":
        clean_project(args.build_dir)

if __name__ == "__main__":
    main()