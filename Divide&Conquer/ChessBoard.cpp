int board[1025][1025];
int tile = 0;//L型骨盘号

/*
(tr，tc)是棋盘左上角的方格坐标
(dr,dc)是特殊方格所在的坐标
size是棋盘的行数和列数
*/
void ChessBoard(int tr, int tc, int dr, int dc, int size) {
    if (size == 1)
        return;
    int t = tile++;
    int s = size / 2;//分割棋盘
    //覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s)
        //特殊方格在此棋盘中
        ChessBoard(tr, tc, dr, dc, s);
    else {
        //棋盘中无特殊方格
        board[tr + s - 1][tc + s - 1] = t;
        //覆盖其余方格
        ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }
    if (dr < tr + s && dc >= tc + s) {
        ChessBoard(tr, tc+s, dr, dc, s);
    }
    else {
        board[tr + s - 1][tc + s ] = t;
        ChessBoard(tr, tc + s, tr + s - 1, tc + s , s);
    }
    if (dr >= tr + s && dc < tc + s) {
        ChessBoard(tr + s , tc, dr, dc, s);
    }
    else {
        board[tr + s][tc + s - 1] = t;
        ChessBoard(tr+s, tc , tr + s , tc + s-1, s);
    }
    if (dr >= tr + s && dc >= tc + s) {
        ChessBoard(tr+s, tc + s, dr, dc, s);
    }
    else {
        board[tr + s ][tc + s] = t;
        ChessBoard(tr + s, tc + s, tr + s , tc + s, s);
    }
}
