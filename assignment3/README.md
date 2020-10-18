# CS205 C/ C++ Program Design



## Assignment 3



**Name**: 成为

**SID**: 11712319 



#### Part 1. Description



- The original code is attached in the following GitHub link：

https://github.com/CHENGWEI-inf/CppAssignments/tree/master/assignment3



###### 1.1 Functions

In the dot product task, we implement 2 types of dot product method: 

- **Plain dot product**: simply multiply and add up
- **Concurrent dot product**: optimize with concurrent programming

Also, we support 2 method to load data in method:

- Read From Command Line
- Read From File

What's more, the program support counting times for measuring performance.  And also attach a script for generating test data.



###### 1.2 Implementation

- The input and output of the dot product method are type of `float`.  However, in order to raise the precision, we use double to store intermedium result while calculating in both methods
- The concurrent method implement in my computer takes advantage of a CPU with <u>4 core and 8 threads</u>, no hyperthreading. Different CPU may cause different result.

- OpenBLAS environment varies, if you want to test OpenBLAS in different computer, edit the `cmake.txt`



#### Part 2. Result

###### 2.1 Result and Performance

The performance of the method is measured and shown in the following screen shot:

![result1](E:\git\Github_Clone\CHENGWEI-inf\CppAssignments\assignment3\files\result1.png)

​						... ...

![result2](E:\git\Github_Clone\CHENGWEI-inf\CppAssignments\assignment3\files\result2.png)



#### Part 3. Difficulties & Solutions, or others

###### 3.1 Difficulties

- Large memory allocate. Solution : compile with amd64
- Concurrent programming
- Precision lost
- BLAS compile