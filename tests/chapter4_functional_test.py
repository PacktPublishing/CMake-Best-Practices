#!/usr/bin/env python3

# Validation code for the chapter-4 examples
#
# SPDX-License-Identifier: MIT

import subprocess
import pytest
import tempfile
import os
import sys
from pathlib import Path
from os.path import exists as file_exists


def get_script_path():
    return Path( __file__).parent

def get_root_project_directory():
    return get_script_path().parent

def get_chapter4_root_directory():
    return get_root_project_directory().joinpath("chapter_4")


CMAKE_COMMAND="cmake"
CPACK_COMMAND="cpack"

def run_command(command, *args):
    """Execute a command with arguments.

    Args:
        command (string): Command to execute
        *args (args list): Arguments to be forwarded to the

    Returns:
        bool: True if command execution did not throw any errors, False otherwise
    """
    try:
        subprocess.run(args=[command, *args], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return True
    except:
        return False

def run_cmake(*args):
    """Run CMake with given args

    Returns:
        bool: True if command execution did not throw any errors, False otherwise
    """
    return run_command(CMAKE_COMMAND, *args)

def run_cpack(*args):
    """Run CPack with given args

    Returns:
        bool: True if command execution did not throw any errors, False otherwise
    """
    return run_command(CPACK_COMMAND, *args)

def test_prerequisites():
    """
    Check overall prerequisites for the tests.
    
    If one of the checks fail, the testing cannot proceed any further.
    """
    assert run_cmake("--version"), "CMake is not present!"
    assert run_cpack("--version"), "CPack is not present!"
    # assert run_command("rpmbuild", "--version"), "rpmbuild is not present!"
    # assert run_command("dpkg", "--version"), "DPKG is not present!"
    assert run_command("tar", "--version"), "TAR is not present!"

class TestChapter4():
    """
    Tests for chapter 4 CMake example content.
    
    This code validates that can be configured, built, installed without any issues. In addition,
    the test code validates installation has installed the expected files (and not installed the unexpected ones) 
    and tries to run the executables.
    """
    temporary_build_root_dir=tempfile.TemporaryDirectory("build")
    temporary_install_root_dir=tempfile.TemporaryDirectory("install")
    temporary_build_root=temporary_build_root_dir.name
    temporary_install_root=temporary_install_root_dir.name
    source_directory=str(get_chapter4_root_directory().absolute())
    
    def test_configure(self):
        """Check if project can be configured
        """
        assert run_cmake("-S", self.source_directory, "-B", self.temporary_build_root)

    def test_build(self):
        """Check if project can be built
        """
        assert run_cmake("--build", self.temporary_build_root,  "--parallel", str(os.cpu_count()))

    def test_install(self):
        """Check if project can be installed
        """
        assert run_cmake("--install", self.temporary_build_root, "--prefix", self.temporary_install_root)

    def test_install_check_files_exists(self):
        """Check if install step has installed the all files that install() commands intend to install
        """
        # Example 1
        assert file_exists(f"{self.temporary_install_root}/bin/ch4_ex01_executable")
        # Example 2
        assert file_exists(f"{self.temporary_install_root}/lib/libch4_ex02_static.a")
        assert file_exists(f"{self.temporary_install_root}/include/chapter4/ex02/lib.hpp")
        # Example 3
        assert file_exists(f"{self.temporary_install_root}/bin/chapter4_greeter_content")
        assert file_exists(f"{self.temporary_install_root}/bin/chapter4_greeter")
        # Example 4
        assert file_exists(f"{self.temporary_install_root}/var/dir1/subdir/asset5.x")
        assert file_exists(f"{self.temporary_install_root}/var/dir1/asset1.x")
        assert not file_exists(f"{self.temporary_install_root}/var/dir1/asset2")
        assert file_exists(f"{self.temporary_install_root}/var/dir2/chapter4_hello.dat")
        assert not file_exists(f"{self.temporary_install_root}/var/dir2/chapter1_hello.hpp")
        assert file_exists(f"{self.temporary_install_root}/var/dir3/asset4")
        assert not file_exists(f"{self.temporary_install_root}/var/dir3/bin/goodbye.dat")
        # Example 5
        assert file_exists(f"{self.temporary_install_root}/lib/libch4_ex05_lib.a")
        assert file_exists(f"{self.temporary_install_root}/include/chapter4/ex05/lib.hpp")
        assert file_exists(f"{self.temporary_install_root}/cmake/ch4_ex05_lib-config.cmake")
        assert file_exists(f"{self.temporary_install_root}/cmake/ch4_ex05_lib-config-version.cmake")
    
    def test_install_run_binaries(self):
        """Try to run executables that installed via install
        """
        assert run_command(f"{self.temporary_install_root}/bin/ch4_ex01_executable")
        assert run_command(f"{self.temporary_install_root}/bin/chapter4_greeter")

    def test_ex05_consumer(self):
        """Check config-file package works by building ex05_consumer after installing the chapter 4 content
        """
        ex05_temporary_build_root_dir=tempfile.TemporaryDirectory("build")
        ex05_temporary_build_root=ex05_temporary_build_root_dir.name
        ex05_source_directory=str(get_chapter4_root_directory().joinpath("ex05_consumer").absolute())
        assert run_cmake("-S", ex05_source_directory, "-B", ex05_temporary_build_root, f"-DCMAKE_INSTALL_PREFIX:STRING={self.temporary_install_root}")
        assert run_cmake("--build", ex05_temporary_build_root,  "--parallel", str(os.cpu_count()))



class TestChapter4Example6():
    """Tests for the packaging example
    """
    temporary_build_root_dir=tempfile.TemporaryDirectory("build")
    temporary_install_root_dir=tempfile.TemporaryDirectory("install")
    temporary_build_root=temporary_build_root_dir.name
    temporary_install_root=temporary_install_root_dir.name
    source_directory=str(get_chapter4_root_directory().joinpath("ex06_pack").absolute())

    def test_configure(self):
        """Check if project can be configured
        """
        assert run_cmake("-S", self.source_directory, "-B", self.temporary_build_root)

    def test_configure_check_files(self):
        """Check if CPack configuration files are present after configuration 
        """
        assert file_exists(f"{self.temporary_build_root}/CPackConfig.cmake")
        assert file_exists(f"{self.temporary_build_root}/CPackSourceConfig.cmake")

    def test_build(self):
        """Check if project can be built
        """
        assert run_cmake("--build", self.temporary_build_root,  "--parallel", str(os.cpu_count()))

    def test_install(self):
        """Check if project can be installed
        """
        assert run_cmake("--install", self.temporary_build_root, "--prefix", self.temporary_install_root)

    def test_install_check_files(self):
        """Check if install step has installed the all files that install() commands intend to install
        """
        assert file_exists(f"{self.temporary_install_root}/bin/ch4_ex06_executable")
        assert file_exists(f"{self.temporary_install_root}/lib/libch4_ex06_library.a")
        assert file_exists(f"{self.temporary_install_root}/include/chapter4/ex06/lib.hpp")

    def test_install_run_binaries(self):
        """Try to run executables that installed via install
        """
        assert run_command(f"{self.temporary_install_root}/bin/ch4_ex06_executable")


    def test_pack(self):
        """Try to pack the project via CPack
        """
        assert run_cpack("--config", f"{self.temporary_build_root}/CPackConfig.cmake", "-G", "TGZ", "-B", f"{self.temporary_build_root}/pak")

    def test_pack_check_files(self):
        """Check whether CPack produced the package files
        """
        # Linux, Windows, and Darwin
        for system_name in ["Linux", "Windows", "Darwin"]:
            if file_exists(f"{self.temporary_build_root}/pak/ch4_ex06_pack-1.0-{system_name}.tar.gz"):
                return True
        assert False, "Package file is not present!"