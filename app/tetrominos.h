/*
 * tetrominos.h
 *
 *  Created on: Feb 2, 2017
 *      Author: patrick
 */

#ifndef APP_TETROMINOS_H_
#define APP_TETROMINOS_H_

#define O {O1}
#define Z {Z1, Z2}
#define S {S1, S2}
#define I {I1, I2}
#define J {J1, J2, J3, J4}
#define L {L1, L2, L3, L4}
#define T {T1, T2, T3, T4}

#define O1 {  \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 7, 7, 0}, \
    {0, 7, 7, 0}, \
}

#define Z1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {1, 1, 0, 0}, \
    {0, 1, 1, 0}, \
}

#define Z2 { \
    {0, 0, 0, 0}, \
    {0, 1, 0, 0}, \
    {1, 1, 0, 0}, \
    {1, 0, 0, 0}, \
}

#define S1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 2, 2, 0}, \
    {2, 2, 0, 0}, \
}

#define S2 { \
    {0, 0, 0, 0}, \
    {2, 0, 0, 0}, \
    {2, 2, 0, 0}, \
    {0, 2, 0, 0}, \
}

#define J1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 3, 0}, \
}

#define J2 { \
    {0, 0, 0, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
    {3, 3, 0, 0}, \
}

#define J3 { \
    {0, 0, 0, 0}, \
    {3, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 0, 0}, \
}

#define J4 { \
    {0, 0, 0, 0}, \
    {0, 3, 3, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
}

#define L1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {4, 4, 4, 0}, \
    {4, 0, 0, 0}, \
}

#define L2 { \
    {0, 0, 0, 0}, \
    {4, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
}

#define L3 { \
    {0, 0, 0, 0}, \
    {0, 0, 4, 0}, \
    {4, 4, 4, 0}, \
    {0, 0, 0, 0}, \
}

#define L4 { \
    {0, 0, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 4, 0}, \
}

#define T1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}

#define T2 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 0, 0}, \
    {0, 6, 0, 0}, \
}

#define T3 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 0, 0, 0}, \
}

#define T4 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {0, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}

#define I1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {5, 5, 5, 5}, \
    {0, 0, 0, 0}, \
}

#define I2 { \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
}

#endif /* APP_TETROMINOS_H_ */