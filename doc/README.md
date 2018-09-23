Introduction
============

In this section I will describe the physics involved in this project to
help people who are not in physics to understand it better. The aim and
importance of this work will also be illustrated.

Atom energy structure
---------------------

According to quantum mechanics, the energy states of atoms is mainly
dedcided by the *primary quantum number n*, based on this, further study
shows that when considering the interaction between electron orbital
angular momentum and electron spin, the energy level of atoms can split
into more sublevels, called *fine structure*, defined by *angular
momentum L*. As a step further, when taking into account the nuclear
spin, these fine energy structures will further split into *hyperfine
structure*, notated by *F*. For a specific number F, there are $2F+1$
magnetic sublevels, noted by $M_F$, where
$M_F = -2F,  -2F + 1, ..., -1, 0, 1, ..., 2F-1, 2F$, as shown in fig
These $M_F$ sublevels have exactly the same energy when there is no
external magnetic field, the phenomenon is called *degenerate*.

Atom-light interaction and selection rules
------------------------------------------

Atom by itself, will stay at the lowest energy level(called *ground
state*) when there is no external field. When there is light interacting
with atoms, especially when the photon (samllest unit of light) has
about the same energy ( or frequency) as certain atom energy level
difference, the atom has a certain chance to change its states to a
higher energy level, called *excited state*. However, the atom will not
be able to stay at the excited states forever, it will spontaneously go
back to some lower levels after a certain time. This procedure is called
*spontaneous decay*, the statistical time is called *lifetime*, which is
usually nanoseconds. as shown in fig Which magnetic substate ($M_F$) the
atom will level up to, is decidecd by the energy of photon and the
polorization of light. There are 3 kind of light polarizations, each of
which can induce a specific transition, called *selection rule*. As
listed below:\

      Polarization                 selection rule
  -------------------- --------------------------------------
   circular $\sigma+$   $M_F\rightarrow M_F\prime = M_F + 1$
   circular $\sigma-$   $M_F\rightarrow M_F\prime = M_F - 1$
      linear $\pi$        $M_F\rightarrow M_F\prime = M_F$

Optical pumping and transition matrix
-------------------------------------

In atomic physics, one of the many useful techniques to control the atom
states at hyperfine level ($M_F$)is *optical pumping*. Optical pumping
is aimed to transfer atoms into a specific states so that researcher can
have a better control of them in experiment. There are usually 3 energy
levels involved in optical pumping, two laser beams at different
frequency (corresponding to two transitions) are used. The way people do
this is to use laser light with controled polarization and frequence to
interact with atoms. while one laser aims to deplete one of the ground
states, the other aims to transfer atoms into specific magnetic
sublevel($M_F$). To be brief, there are two main step to make one
optical pumping cycle: excite and decay. Excite is the process that
atoms absorb photon and jump to excited states, based on selection rule,
interaction with laser is involved during his time. Decay is how atom
gets back to lower level without any interactios, also follows selection
rule.\
The two steps discussed above happen with some statistical probablity,
which is given by the *transition matrix*. Given specific ground state
and excited states, the posibility that govens this transition can be
found from literature, usually documented as relative relative
transition strength, shown in fig \[fig1\] as an example for Lithium.\

\[fig1\]

Aim and importance of this work
-------------------------------

In this work, I’m simulating the optical pumping process of the D1 line
of lithium 7 atoms. In the lab, we are using this optical puming process
to detect lithium atom signal in the vacuum chamber. While normal
fluorescence imaging using a single resonant laser can do the detection
job, optical pumping can allow us to detect much weaker $^{7}Li$
signals, especially the total atoms number to be detected is small.\
Basically we want to transfer all atoms from ground state $F=1$ to
ground state $F=2, M_f = 2$. However, experimently there are two
possible transitions for us to chose for the optical pumping, as shown
in fig \[fig2\].\

\[fig2\]

One is to use excited state $F\prime = 1$ as the medium, which has 3
magnetic sublevels: $M_F = -1, 0, 1$, another choice is to use excited
state $F\prime = 2$, which has 5 magnetic sublevels:
$M_F = -2, -1, 0, 1, 2$.\
In this simulation, I will compare the two different optical pumping
schemas under same physics condition, to figure out which schema will
lead to a faster optical pumping trnasition. The result will be used to
guid our fellowing experiment.

Project
=======

In this section, I’ll show the serial code structure to introduce how
the simulation works. Based on this, I’ll discuss the approach of
parallelizing the code and the reason I’m doing it in this way. By the
end I’ll shown the performance of the parallelized code.\
The project is done with C++, parallized by OpenMP, result plotted by
python.

Code structure
--------------

The code structure is shown is fig \[fig5\].\

\[fig5\]

The simulation is made of 4 parts:

1.  Generate transition matrix

2.  Initialize ground states population

3.  Simulate excitation process for the 2 ground states

4.  Simulate decay process from excited states to 2 ground states

5.  Calculate the new population for the 2 gound states and excited
    state write data to file

6.  Loop the above two steps for giving time (number of loops)

7.  Generate plot for population of different states versus time

Parallelization
---------------

There are multiple loops in the code, so considering using OpenMP to
parallelize some of them.\
Only considering those big loops that under goes lots of computation,
find that there are potentially 4 loops that worth being parallized:

1.  General time step loop. This could have hundreds of thoustands of
    iterations.

2.  Update ground state G1 loop. This has 3 loops, but each loop may
    have heavy computation work.

3.  Update ground state G2 loop. This has 3 loops, but each loop may
    have heavy computation work.

4.  Update Excited state E loop. This also requires a lot of
    computation.

Now I’m going to analyze the possiblity to parallelize each of above
loops:\
For 1, physics of optical pumping requires that each of time step
iterations depend on the previous iteration, since that’s the results of
previous iteration becomes the starting state of the coming iteration.
For this reason, unfortunately, this biggest loop cannot be parallelized
due to the indepedency of each iteration.\
For 2, 3, although this two loop are with the time iteration loop, they
have independency of each iterations, the computation of excitation
process for the two ground states doesn’t depent on the population of
the magnetic sublevels (iterations). Further more these two loop are
computation intensive, since each of the iterations has to do a big
matrix multiply calculation. Based on these facts, this two loops should
be parallelized.\
For 4, this is similar to loop 2 and loop 3, in terms of the
independency and calculation intensity. However, this loop has to be
excuted after the two loop, since one has to check if the loop 2 and
loop 3 have already depleted the ground states, the uptating algorithm
for this loop depend on loop 2 and loop 3. This is in consideration of
the conservation of atoms number (In this simulation, I’m using number
density, so total atom number should always be 1, when sum up each of
the substates). Based on these facts, this loop can be prarllelized, but
it must be excuted after the previous two loops.\
Overall, I decide to parallel the loop 2,3,and 4, while keep the loop 4
excuted after loop 2 and 3. Considering there are only 3 and 5
interations in loop 2 and loop 3, I decide to let each of these 2 loops
excute in parallel but each on one thread. For loop 3, which has 5
calculation intensive iterations, I would assign 5 threads to
parallelizd this region. The diagram for the prarllization as shown in
fig \[fig6\]:\

\[fig6\]

Result and discussion
=====================

By using the parallized code, I simulated the 2 optical pumping schemas:
use $F\prime = 1$ as excited state and use $F\prime = 2$ as excited
state. Here I’ll show one of the comparision under the same physics
condition.

$F\prime = 1$as excited state
-----------------------------

See figure \[fig7\]\

\[fig7\]

$F\prime = 2$as excited state
-----------------------------

See figure \[fig8\]\

\[fig8\]

Discussion
----------

From the plot, one can see that, if choose $F\prime = 1$ as excited
state to do the optical pumping, we cannot transfer all of the
population to a single state, while we can achieve this goal by chosing
$F\prime = 2$ as excited state. while in terms of the time to reach a
stable state, both of these to schema take about the same time. Since
pump the atom into a single state is very important for our experiment,
based on this simulation, we will chose $F\prime = 2$ as the excited
state to do the optical pumping.

Summary
=======

To sum up, starting from a pratical physics problem, simulation code was
written, as a step further, the chose of Parallelization was discussed
and realized by using OpenMp. The simulation results were discussed and
come to a conclusion to help guide the experiment.
