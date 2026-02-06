# Worldr: C++ wordle solver

The goal of wordlr is to create a program to attempt to beat every possible wordle game.
This is done through a simple elimination algorithm for a search engine.



# Building

Do the below in order
Downloading
```
git clone https://github.com/RavenRandomz/ravens-default-cpp23-project.git
```
Generating
```
cd wordlr # if you are already in this dir, do not run this line
mkdir build
cd build
cmake .. -G Ninja #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

Subsequent builds
```
cd build
ninja
# or to utilize parallel processing for that 1337sp33d
ninja -j 0 

```

When you add a file (assuming you are in build dir and already generated the ninja project
```
touch ../CMakeLists.txt # Cmake must believe that the file has "changed" so it can check for stuff
ninja # Will automatically run cmake
```

Alternatively when you add a file - imo, just install coreutils, idk why windows hasn't shipped with them: https://gnuwin32.sourceforge.net/packages/coreutils.htm
```
vim ../CMakeLists.txt # (or whever you use)
# Edit the file in some manner, add a space, save it, then remove the space, 
then save it. The point is to change the last modified time and date to trigger
cmake to search for the new files/regenerate. The ninja config will 
automatically trigger for subsequent builds
```

When you are getting into gdb

Mote that as long as the project type is a ninja one
within the build dir, cmake will just update it to use debug
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

When you want a build without debug symbols/assertions https://gnuwin32.sourceforge.net/packages/coreutils.htm
```
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release #Ninja is cross platform and is one of the few project types that supports modules at the moment with CMakef
```

For more advanced users, look up using ninja multi-config as an option.


# Architecture

* res - contains game files such as victory and valid guess world lists

* game - defines your standard Wordle game such as rounds, a game, which 
  contains rounds (keeps tracks of victories and losses), and dictionaries

* player - user/computer interaction with a worldr round, you'll find bots here

* search - search utilities, a filter checks if a word is valid or not, a search 
  engine uses filters to check for valid words, filters can be combined by the 
  mulitfilter

* word - deprecated


Check the unit tests for usecase examples
