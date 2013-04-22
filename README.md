# VATEDROID: The Tutorial
vatedroid (v8 droid) is a basic sample project demonstrating how to embed v8 in an android application through the android ndk
The ensufire_tutorial branch (the one you are currently on) is tied to [ensufire's vatedroid tutorial](http://www.ensufire.com/2013/03/vatedroid-embedded-v8-in-android.html).
Most of VATEDROID's functionality is stripped out, and tagging follows the tutorial step by step

## Turn this repo into an android project
run the following:

    git clone https://github.com/lorinbeer/vatedroid.git
    cd vatedroid
    git branch ensufire_tutorial --track origin/ensufire_tutorial
    git checkout ensufire_tutorial
    android update project --name vatedroid --target <android-int> --path .

where "<android-int>" is the latest android target installed on your system.
This tutorial was tested with android-17

# Tutorial Parts

## [VATEDROID: Introduction](http://www.ensufire.com/2013/03/vatedroid-embedded-v8-in-android.html)
why we're even doing this

## [VATEDROID: Part 0](http://www.ensufire.com/2013/03/vatedroid-v8-in-android-environment_30.html)
setting up the necessary tools

## [VATEDROID: Part 1](http://www.ensufire.com/2013/04/vatedroid-v8-in-android-environment.html)
compiling V8 for Android

##[VATEDROID: Part 2](http://www.ensufire.com/2013/04/vatedroid-v8-in-android-environment_19.html)
setting up an android NDK module to include V8

###tags
checkout the following tags to see the project at the given tutorial step
- p2s4 - directory structure
- p2s5 - skeleton of vatedroid
- p2s6 - makefile 
- p2s7 - compileable
