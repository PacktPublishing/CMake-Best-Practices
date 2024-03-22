# CMakeLists file for the Chapter 13 Example nr. 01: 
# Git utility module
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch13_ex01_git_module
  VERSION 1.0
  DESCRIPTION "Chapter 13 Example 01, git utility module example"
  LANGUAGES CXX)

include(cmake/git.cmake)

git_get_branch_name(current_branch_name)
git_get_head_commit_hash(current_head)
git_get_config_value("user.name" current_user_name)
git_get_config_value("user.email" current_user_email)

message(STATUS "-------------------------------------------")
message(STATUS "VCS (git) info:")
message(STATUS "\tBranch: ${current_branch_name}")
message(STATUS "\tCommit hash: ${current_head}")
message(STATUS "\tAuthor name: ${current_user_name}")
message(STATUS "\tAuthor e-mail: ${current_user_email}")
message(STATUS "-------------------------------------------")
