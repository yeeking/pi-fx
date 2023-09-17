const int CHAR_WIDTH = 16;
const int CHAR_HEIGHT = 16;

// const int CHAR_WIDTH = 8;
// const int CHAR_HEIGHT = 8;

// This represents the 'A' character in 8x8:
//   #  
//  # # 
// #   #
// #####
// #   #
// #   #
// #   #
// unsigned char CHAR_A[CHAR_HEIGHT] = {
//     0b00100000,
//     0b01010000,
//     0b10001000,
//     0b11111000,
//     0b10001000,
//     0b10001000,
//     0b10001000,
//     0b00000000  // Padding to make it 8x8
// };
// Then you can have a lookup:
// const unsigned char* CHAR_LOOKUP[36] = {
//     CHAR_A, // ... add CHAR_B, CHAR_C, ...
//     // CHAR_0, CHAR_1, ...
// };

const unsigned short CHAR_A[CHAR_HEIGHT] = {
    0b0000001100000000,
    0b0000110010000000,
    0b0001100001000000,
    0b0011000000100000,
    0b0011000000100000,
    0b0011000000100000,
    0b0011111111110000,
    0b0011111111110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000
};

// 'B' in 16x16 with double-thick lines
const unsigned short CHAR_B[16] = {
    0b0011111111100000,
    0b0011111111100000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0011111111100000,
    0b0011111111100000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000110000,
    0b0011111111100000,
    0b0011111111100000
};


// 'C' in 16x16 with double-thick lines
const unsigned short CHAR_C[16] = {
    0b0000111111110000,
    0b0000111111110000,
    0b0001000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0000111111110000,
    0b0000111111110000
};

// 'D' in 16x16 with thicker lines
const unsigned short CHAR_D[16] = {
    0b0011111111100000,
    0b0011111111100000,
    0b0011111111100000,
    0b0010000000110000,
    0b0010000000110000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000110000,
    0b0010000000110000,
    0b0011111111100000,
    0b0011111111100000,
    0b0011111111100000,
    0b0011111111100000,
    0b0011111111100000,
    0b0011111111100000
};

// 'E' in 16x16 with thicker lines
const unsigned short CHAR_E[16] = {
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0010000000000000,
    0b0010000000000000,
    0b0011111111110000,
    0b0011111111110000,
    0b0011111111110000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000
};

// 'F' in 16x16 with thicker lines
const unsigned short CHAR_F[16] = {
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0010000000000000,
    0b0010000000000000,
    0b0011111111110000,
    0b0011111111110000,
    0b0011111111110000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000
};

// 'G' in 16x16 with thicker lines
const unsigned short CHAR_G[16] = {
    0b0001111111111000,
    0b0001111111111000,
    0b0011111111111000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000001111000,
    0b0010000001111000,
    0b0010000000011000,
    0b0010000000011000,
    0b0011111111111000,
    0b0011111111111000,
    0b0001111111111000,
    0b0001111111111000,
    0b0001111111111000,
    0b0001111111111000
};

// 'H' in 16x16 with thicker lines
const unsigned short CHAR_H[16] = {
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000
};

// 'I' in 16x16 with thicker lines
const unsigned short CHAR_I[16] = {
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000
};
// 'J' in 16x16 with thicker lines
const unsigned short CHAR_J[16] = {
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0010000011000000,
    0b0010000011000000,
    0b0010000011000000,
    0b0011111111000000,
    0b0011111111000000,
    0b0001111111000000,
    0b0001111111000000,
    0b0001111110000000,
    0b0000111100000000
};

// 'K' in 16x16 with thicker lines
const unsigned short CHAR_K[16] = {
    0b0010000000111000,
    0b0010000001110000,
    0b0010000011100000,
    0b0010000111000000,
    0b0010001110000000,
    0b0011111100000000,
    0b0011111000000000,
    0b0011110000000000,
    0b0011111000000000,
    0b0010001110000000,
    0b0010000111000000,
    0b0010000011100000,
    0b0010000001110000,
    0b0010000000111000,
    0b0010000000011100,
    0b0010000000011100
};

// 'L' in 16x16 with thicker lines
const unsigned short CHAR_L[16] = {
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000,
    0b0011111111111000
};

// 'M' in 16x16 with thicker lines
const unsigned short CHAR_M[16] = {
    0b0011000000001100,
    0b0011000000001100,
    0b0011100000011100,
    0b0011110000111100,
    0b0010111001111000,
    0b0010111001111000,
    0b0010011011011000,
    0b0010011011011000,
    0b0010001110011000,
    0b0010001110011000,
    0b0010000100011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000,
    0b0010000000011000
};

// 'N' in 16x16 with thicker lines
const unsigned short CHAR_N[16] = {
    0b0011000000011000,
    0b0011100000011000,
    0b0011100000011000,
    0b0011110000011000,
    0b0010111000011000,
    0b0010011100011000,
    0b0010001110011000,
    0b0010000111011000,
    0b0010000011111000,
    0b0010000001111000,
    0b0010000000111000,
    0b0010000000111000,
    0b0010000000011100,
    0b0010000000011100,
    0b0010000000001110,
    0b0010000000001100
};

// 'O' in 16x16 with thicker lines
const unsigned short CHAR_O[16] = {
    0b0001111111100000,
    0b0011111111110000,
    0b0110000000011000,
    0b0110000000011000,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000000001100,
    0b0110000000011000,
    0b0110000000011000,
    0b0011111111110000,
    0b0001111111100000,
    0b0000000000000000,
    0b0000000000000000
};

// 'P' in 16x16 with thicker lines
const unsigned short CHAR_P[16] = {
    0b0011111111100000,
    0b0011111111111000,
    0b0010000000011100,
    0b0010000000001100,
    0b0010000000011100,
    0b0011111111111000,
    0b0011111111100000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000,
    0b0010000000000000
};

// 'Q' in 16x16 with thicker lines
const unsigned short CHAR_Q[16] = {
    0b0001111111100000,
    0b0011111111110000,
    0b0110000000011000,
    0b0110000000011000,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000000001100,
    0b1100000110001100,
    0b1100000111011100,
    0b0110000011111000,
    0b0110000000011100,
    0b0011111111111000,
    0b0001111111110000,
    0b0000000000111100,
    0b0000000000011100,
    0b0000000000001100
};

// 'R' in 16x16 with thicker lines
const unsigned short CHAR_R[16] = {
    0b0011111111000000,
    0b0011111111110000,
    0b0010000000111000,
    0b0010000000011000,
    0b0010000000111000,
    0b0011111111110000,
    0b0011111111000000,
    0b0010000111000000,
    0b0010000011100000,
    0b0010000001110000,
    0b0010000000111000,
    0b0010000000011100,
    0b0010000000011100,
    0b0010000000001110,
    0b0010000000001110,
    0b0010000000000111
};

// 'S' in 16x16 with thicker lines
const unsigned short CHAR_S[16] = {
    0b0000111111110000,
    0b0011111111111000,
    0b0110000000011100,
    0b0110000000011000,
    0b0111000000000000,
    0b0011111111100000,
    0b0000111111110000,
    0b0000000011111000,
    0b1100000000011100,
    0b1100000000011100,
    0b0110000000011100,
    0b0111111111111000,
    0b0001111111110000,
    0b0000000000000000,
    0b0000000000000000,
    0b0000000000000000
};

// 'T' in 16x16 with thicker lines
const unsigned short CHAR_T[16] = {
    0b1111111111111111,
    0b1111111111111111,
    0b0011111111111000,
    0b0011111111111000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000,
    0b0000000011000000
};
// 'U' in 16x16 with thicker lines
const unsigned short CHAR_U[16] = {
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011000000011000,
    0b0011100000111000,
    0b0011111111110000,
    0b0001111111100000,
    0b0000000000000000,
    0b0000000000000000,
    0b0000000000000000
};

// 'V' in 16x16 with thicker lines
const unsigned short CHAR_V[16] = {
    0b0110000000011000,
    0b0110000000011000,
    0b0110000000011000,
    0b0110000000011000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011100001100000,
    0b0001100011000000,
    0b0001100011000000,
    0b0000110110000000,
    0b0000110110000000,
    0b0000011100000000,
    0b0000011100000000,
    0b0000001000000000,
    0b0000001000000000
};

// 'W' in 16x16 with thicker lines
const unsigned short CHAR_W[16] = {
    0b1100000000000011,
    0b1100000000000011,
    0b1100000000000011,
    0b0110000000000110,
    0b0110000000000110,
    0b0110000000000110,
    0b0110011000110110,
    0b0011011001101100,
    0b0011011001101100,
    0b0011011001101100,
    0b0011111111111000,
    0b0001110111100000,
    0b0001110111100000,
    0b0001100011000000,
    0b0001100011000000,
    0b0001100011000000
};

// 'X' in 16x16 with thicker lines
const unsigned short CHAR_X[16] = {
    0b0110000000011000,
    0b0110000000011000,
    0b0011000000110000,
    0b0011100001100000,
    0b0001100011000000,
    0b0000110110000000,
    0b0000111100000000,
    0b0000011000000000,
    0b0000111100000000,
    0b0000110110000000,
    0b0001100011000000,
    0b0011100001100000,
    0b0011000000110000,
    0b0110000000011000,
    0b0110000000011000,
    0b0110000000011000
};

// 'Y' in 16x16 with thicker lines
const unsigned short CHAR_Y[16] = {
    0b0110000000011000,
    0b0110000000011000,
    0b0011000000110000,
    0b0011000000110000,
    0b0011100001100000,
    0b0001100011000000,
    0b0000110110000000,
    0b0000111100000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000
};

// 'Z' in 16x16 with thicker lines
const unsigned short CHAR_Z[16] = {
    0b0111111111111100,
    0b0111111111111100,
    0b0110000000011100,
    0b0000000000111000,
    0b0000000001110000,
    0b0000000011100000,
    0b0000000111000000,
    0b0000001110000000,
    0b0000011100000000,
    0b0000111000000000,
    0b0001110000000000,
    0b0011100000000110,
    0b0111111111111110,
    0b0111111111111110,
    0b0111111111111110,
    0b0000000000000000
};

const unsigned short NUM_0[16] = {
    0b0001111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111110000
};

const unsigned short NUM_1[16] = {
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000,
    0b0000001110000000
    
};

const unsigned short NUM_2[16] = {
    0b0001111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0000000000011000,
    0b0000000000110000,
    0b0000000001100000,
    0b0000000011000000,
    0b0000000110000000,
    0b0000001100000000,
    0b0000011000000000,
    0b0000110000000000,
    0b0001100000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011111111111100,
    0b0011111111111100
    
};

unsigned short NUM_3[16] = {
    0b0001111111110000,
    0b0011000000001100,
    0b0000000000001100,
    0b0000000000011000,
    0b0000000000110000,
    0b0000011111100000,
    0b0000011111100000,
    0b0000000000110000,
    0b0000000000001100,
    0b0000000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111110000
    
};

unsigned short NUM_4[16] = {
    0b0000000001100000,
    0b0000000011100000,
    0b0000000111100000,
    0b0000001101100000,
    0b0000011001100000,
    0b0000110001100000,
    0b0001100001100000,
    0b0011000001100000,
    0b0011000001100000,
    0b0011000001100000,
    0b0011111111111100,
    0b0000000001100000,
    0b0000000001100000,
    0b0000000001100000,
    0b0000000001100000,
    0b0000000001100000
};

unsigned short NUM_5[16] = {
    0b0011111111111100,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011000000000000,
    0b0011111111110000,
    0b0000000000001100,
    0b0000000000001100,
    0b0000000000001100,
    0b0000000000001100,
    0b0000000000011000,
    0b0000000000110000,
    0b0000000001100000,
    0b0011111111000000,
    0b0000000000000000
    
};

unsigned short NUM_6[16] = {
    0b0000000111111000,
    0b0000011100000000,
    0b0000110000000000,
    0b0001100000000000,
    0b0011000000000000,
    0b0011111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111110000
    
};

unsigned short NUM_7[16] = {
    0b0011111111111100,
    0b0011000000001100,
    0b0000000000011000,
    0b0000000000110000,
    0b0000000001100000,
    0b0000000011000000,
    0b0000000110000000,
    0b0000001100000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000,
    0b0000011000000000    
};


unsigned short NUM_8[16] = {
    0b0001111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111110000
};

unsigned short NUM_9[16] = {
    0b0001111111110000,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0011000000001100,
    0b0001111111111100,
    0b0000000000001100,
    0b0000000000011000,
    0b0000000000110000,
    0b0000000001100000,
    0b0000000011000000,
    0b0001111110000000
};



// ... Similarly for other characters ...

const unsigned short* CHAR_LOOKUP[36] = {
    CHAR_A, 
    CHAR_B, 
    CHAR_C, 
    CHAR_D, 
    CHAR_E, 
    CHAR_F,
    CHAR_G, 
    CHAR_H, 
    CHAR_I, 
    CHAR_J, 
    CHAR_K, 
    CHAR_L,
    CHAR_M,
    CHAR_N,
    CHAR_O,
    CHAR_P,
    CHAR_Q,
    CHAR_R,
    CHAR_S,
    CHAR_T,
    CHAR_U,
    CHAR_V,
    CHAR_W,
    CHAR_X,
    CHAR_Y,
    CHAR_Z, 
    NUM_0, 
    NUM_1, 
    NUM_2, 
    NUM_3, 
    NUM_4, 
    NUM_5, 
    NUM_6, 
    NUM_7, 
    NUM_8,
    NUM_9 
};