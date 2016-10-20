experiments-cxx
===============

This repository consists of both experimental and tutorial codes.

Investigate:
===========
Test if inline keyword is needed for template function that are defined outside
of the class body

Result:
=======
It didn't cause multiple definition.  Even when multiple cpp files use a sinle
template hpp.
