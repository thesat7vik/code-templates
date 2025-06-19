@echo off
gen>input.txt
sol<input.txt>output.txt
stupid<input.txt>correct.txt 
fc output.txt correct.txt 
if errorlevel 1 pause 
test