# { Algebra of Sets }

## About

Algebra of Sets is an application developed for the discipline of Discrete Mathematics in order to deepen the knowledge about set theory. It implements functions about operations between sets.

## Tecnologies

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

The file ```set.txt``` have to be written in a specific formatting:
  
- For Sets, use:  
**A = {1, 87, 4, -1, 43}**  
*A single capitalized letter, followed by an equal sign, open brackets, n elements separated by a comma, close brackets.*  
  
- For Elements, use:
**b = 30**  
*A single non capitalized letter, an equal sign, a value*  

Spaces are disconsidered.  
>A validation for this file is not implemented. If the file is not written in the right way, the program may crash.  

## Usages
When the program starts, it show the Sets and Elements founded in the file ```set.txt```.  
With these, you can choose one of the following operations:  

- Union
- Subtraction
- Intersection
- Belongs
- Does not belong
- Subset
- Not Subset
- Proper subset
- Not proper subset
- Cartesian Product
- Powerset
  
> Each of these operators has adequate syntax and semantic usage. See Wiki to learn more.
