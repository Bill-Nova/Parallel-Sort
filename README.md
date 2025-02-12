To be honest, if your computer is not a cluster, it can't be very fast, because you can't achieve parallelism >= N

I only describe the idea because the code is very simple(I didn't write a faster version of the code because my computer can't test this.....However, I think the optimized version of this algorithm can reach logN as fast as possible, when the parallelism reaches the maximum value N^2/2)

For sequential programs, speed = number of instructions executed, but for parallel programs, things are different.

For parallel programs, the fastest speed depends on your maximum number of parallel

Even if it is the so-called N^2, as long as N instructions can be executed simultaneously, the speed is equivalent to the so-called N (that is, the code above)

That is, as long as there is unimaginable parallelism, the speed can be faster.
