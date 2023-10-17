# Bytecrafters Unite: The Monty Collaborative Saga

![LIFO-FIFO](https://thumbs.dreamstime.com/b/lifo-fifo-last-first-out-symbol-changes-concept-words-lifo-to-fifo-wooden-blocks-beautiful-grey-table-grey-background-243406275.jpg)

## Table of Contents

- [Introduction](#introduction)
- [Monty bytecode](#monty-bytecode-files)
- [Features](#features)
- [Resources](#resources)
- [Monty Interpreter Testing](#monty-interpreter-testing)
- [Limitations](#limitations)
- [Contact](#contact)

## Introduction

Welcome to Monty 0.98, a script language akin to Python, employing Monty bytecodes. It orchestrates an exclusive stack structure, guided by specialized instructions, creating a melodious blend of code and innovation in a compact, stack-based realm.
Join us on this collaborative odyssey, where we unravel the secrets of Monty bytecode, combining simplicity and ingenuity. Together, we compose a digital sonnet, crafting a world where code and creativity unite in open-source harmony.

## Monty bytecode files

Monty byte code files bear the .m extension, an industry norm but not a language requirement. Each line in these files features a single instruction, allowing flexible spacing around the opcode and its argument. More details and examples can be found in the examples section.

## Features

- 🧐 Unravel the mysteries of LIFO (Last In, First Out) and FIFO (First In, First Out) like a Monty magician.
- 📚 Grasp the essence of stacks and their ideal use cases, letting you wield their power with finesse.
- 🚶‍♂️🚶‍♀️ Explore the realm of queues, understanding their purpose and when to deploy them in the coding adventure.
- 🧮 Dive into various implementations of stacks and queues, learning the alchemy that makes them tick.
- 🌆 Discover the most common scenarios where stacks and queues shine, becoming a wise code architect.
- 🧪 Experiment with global variables, understanding their role in the Monty orchestra, as you compose a symphony of code.
- 🧙‍♂️ Embrace the art of data structures, forging your path to Monty mastery.
- 🌌 Traverse the universe of memory allocation, dancing through its intricate steps with elegance.
- 🪄 Weave the threads of error handling into your code tapestry, ensuring Monty's reliability.
- 🚀 Embark on an epic journey in code optimization, unlocking Monty's hidden powers and making your spells more potent with each enchanting line.

## Resources

- In Monty's journey, where code dreams gleam, these resources hold the keys to a stack and queue's theme.

[Stack and Queues](https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/)

[Everything Stack-Queues](https://everythingcomputerscience.com/discrete_mathematics/Stacks_and_Queues.html)

## Compilation

- To weave this symphony, with lines of code we cast and compile with precision using this spells:

    ```bash
    cd monty
    gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
    ```

## Monty Interpreter Testing

Take these tests and unlock the power of Monty bytecode in your coding journey! 🛣️🚶🚶‍♂️🚶‍♀️

<details>

<summary><strong>Testing LIFO Magic</strong></summary>

1. Create a new Monty script file named `lifo_test.m` and open it with your favorite text editor.
2. Add the following Monty bytecode to the script:

   ```plaintext
   push 1
   push 2
   push 3
   pall

3. Save the script file and close the text editor.
4. In your terminal, run the Monty interpreter with the script:

    ```bash
    ./monty lifo_test.m
    ```

5. Witness the magic as it displays the values in LIFO (Last In,  First Out) order:

    ```plaintext
    3
    2 
    1
    ```

### Unleashing FIFO Sorcery

1. Create another Monty script file named `fifo_test.m` and open it with your mystical text editor.
2. Craft the following Monty bytecode incantation:

    ```plaintext
    push 1
    push 2
    push 3
    pall
    ```

3. Open your terminal and command the Monty interpreter to read the script.

    ```plaintext
    ./monty fifo_test.m
    ```

4. Behold the enchantment as it reveals the values in FIFO (First In, First Out) order:

    ```plaintext
    1
    2
    3
    ```

### Journey into Error Realms

1. Forge a Monty script called error_test.m and let your code adventures begin.
2. Insert the following Monty bytecode in your script:

    ```plaintext
    pop
    pchar
    ```

3. Save the script and release your text editor for a moment.
4. Cast the Monty interpreter spell on the script: `./monty error_test.m`
5. Witness the incantation's consequences as it dances with errors, unraveling the mysteries of error handling.

    ```javascript
    Error: Can't pop an empty stack
    ```

### Code Optimization Quest

1. Embark on an epic code optimization quest with a script named `optimize_test.m`
2. Channel your knowledge into this Monty bytecode masterpiece

    ```javascript
    push 5
    push 10
    mul
    pall
    ```

3. Save your script
4. Open your terminal, and set the Monty interpreter on the script: `./monty optimize_test.m`
5. Experience the results as Monty's magic optimizes your code and leaves you in awe.

    ```javascript
    50
    ```

</details>

## Limitations

In the evolving world of Monty's dream, where code adventures gleam, amidst its grace, acknowledge the boundaries of this code scheme:

1. **Limited Feature Set:** The Monty interpreter may not offer the extensive feature set of more mature languages or interpreters. Advanced or specialized functionalities might be absent.

2. **Error Handling:** Error handling in Monty might not be as comprehensive as in established languages, which could lead to unexpected behavior or error messages.

3. **Compatibility:** Monty may not be compatible with all systems or platforms, potentially resulting in compatibility issues on certain operating systems.

4. **Performance:** Due to its minimalistic design, certain operations within Monty might exhibit slower performance compared to highly optimized languages or interpreters.

5. **Bugs and Incompleteness:** Monty might have unresolved bugs or areas where certain features are incomplete. Users should be aware that it's a work in progress and an educational project.

For every challenge we encounter, an opportunity to refine and explore, in the hands of fellow coders, Monty's potential we implore. As the project evolves, we welcome contributions from fellow adventurers to address these limitations.

## Contact

For queries, echoes, and thoughts that bloom and fuss, don't hesitate to connect, in our haven. [Cletus Samuel](https://cletsymedia.github.io/Prof-Portfolio/) and [Amanda Obi](https://github.com/ObiChika)🙏🙏🙏🙏🙏🙏🙏
