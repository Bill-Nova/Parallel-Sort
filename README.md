To be honest, if your computer is not a cluster, it can't be very fast, because you can't achieve parallelism >= N

For sequential programs, speed = number of instructions executed, but for parallel programs, things are different.

For parallel programs, the fastest speed depends on your maximum number of parallel

Even if it is the so-called N^2, as long as N instructions can be executed simultaneously, the speed is equivalent to the so-called N (that is, the code above)
