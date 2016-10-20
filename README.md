experiments-cxx
===============

This repository consists of both experimental and tutorial codes.

Investigate
===========
What noexcept does?

Result
======
When noexcept is applied to then function.  That disable the ability to throw.
It will still call std::terminate if that function does throw.  The noexcept
is not an indicator that the function won't throw, it is used for the compiler
to optimize the function further.


1. Because if it throws and I do not catch it, std::terminate will be called and I do not want this to happen.
2. Because I need this function to provide no-throw exception safety guarantee.
3. Because this may allow certain compiler optimizations.

It doesn't do 1, nor 2.

It does optimize for 3 but not a whole lot
