# fare
A minimal make like build tool to assist you faster building and testing your projects. The targets are written in the 'Faregets' file which should be in the root of your project. You can use fare to run as many commands as you need under a specific target.

## Installation
To compile fare after cloning this repository you can run:
```
mkdir bin/
gcc src/fare.c -o bin/fare
```
To use fare everywhere you can now add the executable to your path.

## Usage
### Specify Targets
Create the 'Faregets' file in your projects root which can look like this:
> Faregets
```
!build
[1. Command for building project]
[2. Command for building project]
[...]

!run
fare build
[Command for running project]
```
You can find an example 'Faregets' file in the root of this project.

### Run Targets
Run the first target with:
```
fare
```
Or run a specific target with:
```
fare [target name]
```
In your 'Faregets' you can specify as many targets as you want but it is important that there is no left spaces behind your target name definitions.

## Compile fare using fare
If you already have fare installed on your system you can run `fare` in the root of fare project to compile it that way.
