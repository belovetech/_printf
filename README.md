# Welcome to My Printf

---

## Task

my_printf function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char _ argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void _ pointer argument is printed in hexadecimal.

## Description

Loop through the string passed to the function and check for percent sign (%). The percent sign signifies that the next character needs to be formatted. I implemented a check flag dunction that check for the type of flag and format it accordingly.

## Installation

make all

## Usage

```
./my_printf
```

### The Core Team

Abeeb Raheem

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
