# InfoEducație CTF

## Initiation

Simply reversing the given string we find the flag `potato45`

## Challenge 2

We can see 2 photos, one showing 4 international maritime signal flags (Delta Oscar Mike Echo) and 4 flag semaphores (T O W N)

Thus, the flag is `dometown`

## Strange letters on the wall

We can observe a text in a foreign alphabet. After some searching, we find the alphabet is Tifinagh. We can decode it with the help of the internet, for example by using the table [here](https://en.wikipedia.org/wiki/Berber_Latin_alphabet).

## Detective work

This is where things get interesting. We have 3 PNG files, with nothing getting revealed by altering the contrasts and color channels. Running zsteg however, we find 3 base64 encoded strings, one in each PNG file, hidden in the least significant bits of the RGB channels.

Each string contains some cryptic instructions about contacting some person and telling them something. After some searching, we find the descriptions of the people mentioned in the instructions to coincide with the profile pictures of 3 InfoEducație judge members. Following the instructions and telling them what needed to be told, we get 3 numbers - 242 396 811 - and concatenating them to get `242811396` will complete this challenge.

## Numerical sequence

We see a list of random precision floating point numbers, arranged in what seem to be pairs as some of them repeat themselves. Putting each pair into Google Maps and taking the name of each city the pin lands in, we get our flag for this challenge: `pepsicrocodile`

## Treasure Hunt

A long setup for what is essentially moving a set of coordinates by a specified amount n times. We can deduce approximately where the points need to end up by looking at coordinates where one of the movements is 0, and by some trial and error we find n=2020. Plotting the resulting points, we get "hack", and thus our flag: `{hack}`.

## Encodeception (bonus room)

Judging by the title, this challenge consists of applying multiple decoding operations in succession to the text, like so:

- ROT13
- base64
- base64
- reverse

We end up with a string that starts and ends like a base64 encoded message, but is broken up by groups of 2 digits. However, we can observe that these numbers all have digits between 1-5, leading us to a Polybius cipher. Furthermore, we'd expect a base64 string of this length to contain at least a few lowercase letters, so we can deduce that every separated number pair is in fact a lowercase letter encoded with a Polybius square. Thus we replace every 2 digit group with its decoded equivalent, run it through base64, reverse the result and obtain our flag: `ptolomeu48`

## The room is crowded

Oh nice, a CS problem. First off, we can use a bit of deduction skills to guess X and Y. By calculating the gaps between each teams (programatically), we observe teams 35 and 36, which have a gap of around 20 between them, much higher than the others. We can then deduce with pretty high certainty that our team will go here, as it would be too expensive to move teams over that gap.

Next, we'll focus on the actual moving. We'll need to move the teams before 35 (including 35) clockwise, and the teams after 36 counter-clockwise, such that the gap between 35 and 36 is >= 45. A quick and dirty C++ program will help us narrow down the exact minimum intervals that can be a candidate and that will form a gap >= 45,  and then, because I'm lazy, we get out a piece of paper and a calculator and calculate the costs by hand, as there are only 13 possibilities :)

Calculating it by hand however proved quite cumbersome, but by carefully skipping over ones that could clearly not be the minimum, we arrive at the solution: we place our team between 35 and 36, we move teams 28-35 clockwise and teams 36-44 counter-clockwise and get our flag: `{28, 35, 36, 44}`

## QR Code

The image is initially confusing. The black borders around the code might lead you to think that's where the flag is encoded, because encoding something in a nyan cat pixel art seems impossible, right? However, the image turns out to be a Piet program, and running it through an interpreter gives us our flag: `{484438374D4150}`.
