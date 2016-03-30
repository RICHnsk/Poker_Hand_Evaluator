# Poker_Hand_Evaluator
A little piece of code that evaluates 7 card poker hand.

Hi, I am not really a programmer, just toying with poker software. Here's the thing.
Inspired by famous TwoPlusTwo thread and Cactus Kev web page I have tried to make my own evaluator.
Yet again inspired by Ace_eval by ashelly i've tried to make source code as short as possible and finally squeezed it into 517 bytes:)
But it comes with a binary file of 705KiB :/ Funny moment is that obfuscated code works just a tiny bit faster. 

Is it fast? Well, it's not too slow, i guess. It does enumerating test with all 134M combinations in 0.7 sec compared to 0.28 for RayW's code and 1.44 for Steve Brecher's. When it comes to random hands it does 4M evaluations in 0.61 sec, 0.56 for Steve Brecher's and 1.74 for RayW's (cache misses are merciless). So it's pretty much universal.

How to use

It's fairly simple function. First you have to initialize lookup tables from binary files with initHR() function, then pass 7 cards to Eval function as integers from 0 to 51. Output is Cactus Kev's equivalence classes, however reduced from 7462 to 4824 distinct classes (as we have less distinct hands on 7 cards). EQ class #1 stand for royal flush, #4824 stands for nine-high (9 8 7 5 4). So the BETTER the hand the LESS its EQ class value.

Well, that's it! Best of luck!
