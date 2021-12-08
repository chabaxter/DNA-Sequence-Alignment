/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Charles Baxter

Hours to complete assignment: 3

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
The dynamic programming approach was taken. This was used as it is the fasted
to run and memory was not an issue for most of the given problems. This
approaches uses O(N^2) memory but completes in O(N) time.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:
atattat
tattata

Expected output:
-atattat
tattata-

What happened:
atattat
tattata

/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
The computer has 32GB of RAM available. This means that programs have the
ability to use that much memory (the O.S. won't allow this but that's just
semantics). This tells us the limit for how long the input sting can be, as
the required memory to run the algorithm is m x n in space.


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 2

8,000,000,000 = 4 * N ^ 2
2,000,000,000 = N ^ 2
44721.35955

largest N = 44721

The matrix is used to store the data, so its size will be of N * M units.
in this case, N = M, so it will be of size N ^ 2 units. each unit takes
up the size of an integer, which is 4 bytes, so its size will be 
4 * N ^ 2.

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
The closest file to the 44721 length was 50000. This was run using valgrind.
It ran successfully and there were no memory leaks. about 10GB was allocated,
which makes sense as the length of the input was larger than what was used
to calculate the 8GB max.

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
./ *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		 118		 0.054		  25.166
ecoli5000.txt		 160		 0.144		 100.139
ecoli7000.txt		 194		 0.194		 196.293
ecoli10000.txt		 223		 0.474		 400.346
ecoli20000.txt		3135		 2.008		1610.613
ecoli28284.txt		8394		 4.328		3221.225

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 2E-8
b = 1.8428
largest N = 7189135

Excel was used to calculate an equaiton for the time to run. Plugging in
1 day = 86400 seconds, basic algebra is used to solve for largest N.

**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
The lambda expression was used to get the string inputs from stdin. stdin
was redirected when the program was ran to take any inut file directed.

main.cpp - line 20

    auto getStr = []()->std::string {
        std::string out;
        std::cin >> out;
        return out;
    };

    EDistance e(getStr(), getStr());

the lambda returns a string, so the object can be initialized by calling the
lambda function
**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
the min function written for the EDistacne object takes three int parameters.
the std::min function takes two. In order to take the minimum of three numbers;
std::min must be called twice. This inheritantly causes this method to take longer.
The std::min function also is a template function, whereas the EDistance::min function
is not.

to test, three arrays of 30000 random numbers between -100 and 100 were created. The 
minmum was calculated from all three at each coresponding index. The min was calculated
either using EDistance::min or std::min.

for testing of min function:
my min:
	337900 nanoseconds
	333100 nanoseconds
	336300 nanoseconds

std::min:
	465500 nanoseconds
	465600 nanoseconds
	465300 nanoseconds