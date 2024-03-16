# Restaurant Application 
## Program Description: 
Take orders for a sample restaurant. Can order as a guest or an optional login/signup for 
the loyalty rewards program. Afterwards, a menu is available that can order multiple items as well as
customization for all items.

## GTEST information
cmake is a massive build system and adds over 25 files to the repository, so for simplicity the program does not use cmake.
Since the Gtests were made using CMAKE they cannot be ran, however the code and some Gtest related cmake files are left available for review. 
For simplicity of outside user's being able to run the program if they would like, a makefile is used instead for the main program and any
cmake generated files are removed.
