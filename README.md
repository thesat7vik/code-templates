## Configuring Competitive Programming in VSCode (Windows)

In the `tasks.json` file, we can define `LOCAL` macro (useful for debugging later on), increase stack memory to `256 MB` and optimize with `-O2` flag.
```json
"args": [
  "-DLOCAL",
  "-Wl,--stack=268435456",
  "${file}",
  "-O2",
  "-o",
  "${fileDirname}/${fileBasenameNoExtension}.exe"
],
```
These arguments will only compile the code. The program can be executed in the integrated terminal itself.
To run the solution after it is compiled, we can simply use the following in the integrated terminal.

```bash
sol < in
```
This will run `sol.cpp` (`sol.exe`) taking `in` as input.

### Stress Testing
[Based on tourist's method of stress testing](https://youtu.be/JU3HY5GLVnY?t=3526)
1. `sol.cpp`: file for your solution (which is wrong on some hidden testcase).
2. `stupid.cpp`: file for the slower solution (which is correct on testcases).
3. `gen.cpp`: file for your generator function (which generates testcases).
4. `test.bat`: a batch script that automates generating and comparing solutions.

It is convenient to use `in` for input, `out` for output and `ok` for output of slower solution.
Additionally, we can use `in2`, `in3` and so on for multiple inputs (such as in AtCoder or Codeforces sometimes).

`test.bat`
```batch
@echo off
gen >in 
sol <in >out
stupid <in >ok 
fc out ok 
if errorlevel 1 pause
test
```

- In VSCode integrated terminal, using the `exit` command will close the integrated terminal, making it a hassle to reopen it for other commands.
 To avoid this, the script uses `pause`, which halts the script and then we can press `Ctrl+C` to terminate the script.
- If we open `test.bat` in CMD or some separate terminal, then we can simply use `exit` in place of `pause` to close the terminal after finding error.

**Note: if there is no difference in output of both `sol.cpp` and `stupid.cpp` then `test.bat` will run indefinitely until it finds a testcase where there is a discrepancy or until it is terminated.**

It is strongly recommended to use Mersenne Twister to generate random testcases. For reasons why,
https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/ \
https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/

## Example of generating random number
```cpp
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N = rng() % 10 + 5;
```
The above code will generate N randomly from 5 to 14.
