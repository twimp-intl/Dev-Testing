#!/usr/bin/python3
import argparse
import autopep8
import os

def fix_indentation(file_path):
    with open(file_path, 'r') as file:
        code = file.read()
    
    fixed_code = autopep8.fix_code(code)

    with open(file_path, 'w') as file:
        file.write(fixed_code)

def main():
    parser = argparse.ArgumentParser(description='Fix tab and space usage and indentation in Python scripts.')
    parser.add_argument('file', type=str, help='The Python file to be fixed')
    args = parser.parse_args()

    file_path = args.file

    if not os.path.isfile(file_path):
        print(f'Error: The file "{file_path}" does not exist.')
        return

    fix_indentation(file_path)
    print(f'File "{file_path}" has been fixed.')

if __name__ == '__main__':
    main()
