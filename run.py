import os
import shutil
import sys

def build_project(build_dir="build"):
    """build_project using cmake
      Args:
      build_dir: build directory
      """
    #if the build directory not exists create it
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)
    #set the build directory
    os.chdir(build_dir)
    #Rum Cmake
    os.system("cmake ..")

def clean_project(build_dir="build"):
  """
    Clean project
  Args:
    build_dir: build directory
  """

  # Elimina el directorio build si existe
  if os.path.exists(build_dir):
    shutil.rmtree(build_dir)

if __name__ == "__main__":
  if len(sys.argv) > 1:
    command = sys.argv[1]
    build_dir = sys.argv[2] if len(sys.argv) > 2 else "build"

    if command == "build":
      build_project(build_dir)
    elif command == "clean":
      clean_project(build_dir)
    else:
      print("Invalid option. Please, use nexts option build, clean")
  else:
    print("Uso: python run.py <comando> [directorio]")