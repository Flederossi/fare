# fare
A minimal make like build tool to assist you faster building and testing your projects. The targets are written in the 'Faregets' file which should be in the root of your project. You can use fare to run as many commands as you need under a specific target.

## Installation
> To compile fare after cloning this repository you can run:
> ```
> mkdir bin/
> gcc src/fare.c -o bin/fare
> ```
> To use fare everywhere you can now add the executable under bin/ to your path.

## Usage
### Specify Targets
> You can specify targets with a '!' in front of them. The commands that will be executed when the target is called you can simply write under your target definition.
> Create a 'Faregets' file in your projects root which has this structure:
> ```
> ![1. target name]
> [1. command under 1. target]
> [2. command under 1. target]
> [...]
> 
> ![2. target name]
> [1. command under 2. target]
> [...]
> ```
> You can find an example 'Faregets' file in the root of this project.

> **Note: In your 'Faregets' you can specify as many targets as you want but it is important that there is no left spaces behind your target name definitions.**

### Create Dependencies
> To create dependencies from other targets you can run this dependency as seperate command in a target like this:
> ```
> !build
> gcc main.c -o out
> 
> !run
> fare build
> ./out
> ```
> With that a dependency of the target build was created for the target run.

### Run Targets
> Run the first target with:
> ```
> fare
> ```
> Or run a specific target with:
> ```
> fare [target name]
> ```

## Compile fare using fare
> If you already have fare installed on your system you can run `fare` in the root of fare project to compile it that way.
