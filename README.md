# cttt-decomp
A decompilation of the Nintendo Switch version of Captain Toad: Treasure Tracker [v1.3.0].

<img src="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/shibbo/cttt-decomp/main/data/percent.json?token=GHSAT0AAAAAABQVV32DV7KL6LDMN74ZLIDSYPGCQBA&style=flat" />
<a href="https://discord.gg/x7qhJKU3QN">
<img src="https://img.shields.io/discord/932498947715522610?logo=discord"
    alt="chat on our Discord"></a>

## Build Instructions

1. Obtain a clean copy of a `main` from Captain Toad: Treasure Tracker v1.3.0 and rename it to `cttt.nso`, and place it on the root.
2. Run `setup.py` to download and install all of the dependencies. These dependencies are `capstone`, `elftools`, `lz4`, `ninja`, and `colorama`. It will also download a zipped file that contains the compiler and other headers for easy use of the NNSDK.
3. Run `build.py`, then use `check.py` to verify matching status. For more information, see docs/Contributing.

## Contributions

Want to contribute, or learn how to contribute? Try joining our Discord server (link is at the top), and looking into docs/Contributing! We will be glad to answer any questions for people who wish to contribute. All pull requests and issues are welcome.