# { Algebra of Sets }

## About

Algebra of Sets is an application developed for an assignment of a Discrete Mathematics class. It  implements the basic operations related to sets.

## Technologies

* C Language

## Setup

#### File Structure

When the program starts, it will search for a file called ```set.txt```, that have to be with the executable code, or in the folder before. The file structure should be one of these that follows:

```
project
│   executable.exe
│   set.txt    
│
```
or

```
project
│   set.txt
│
└───folder
    │   executable.exe
    │   
```

>If the program didn't find the set.exe file, it reports an error and closes.

#### Formatting ```set.txt``` 

The file ```set.txt``` have to be written in a specific format so the program can function.  
Each line of this file should contain a definition of a `Set` or `Element`.
  
- For `Sets`, use:  
```
A = {1, 87, 4, -1, 43}
```  
*A single capitalized letter, followed by an equal sign, open brackets, n elements separated by a comma, close brackets.*  
  
- For `Elements`, use:
```
b = 30
```   
*A single non capitalized letter, an equal sign, a value*  

Spaces are disconsidered.  

## Usages
When the program starts, it shows the Sets and Elements founded in the file ```set.txt```.  
With these, you can choose one of the following operations and executing them accordingly to the operator assigned to it:

- `Union:......................... +`
- `Subtraction:................... -`
- `Intersection:.................. *`
- `Belongs:....................... <`
- `Does not belong:............... >`
- `Subset:........................ (`
- `Not Subset:.................... )`
- `Proper subset:................. [`
- `Not proper subset:............. ]`
- `Cartesian Product.............. x`
- `Powerset:...................... P()` 
  
> Each of these operators has adequate syntax and semantic usage. 

## More
For further information visit the [Wiki](https://github.com/LBeghini/Algebra-of-Sets/wiki).
