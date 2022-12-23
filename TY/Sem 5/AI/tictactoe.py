# define the board as a list of lists
board = [[' ',' ',' '],
         [' ',' ',' '],
         [' ',' ',' ']]

# define the players as constants
X = 'X'
O = 'O'

# define a function to print the board
def print_board():
    print(f' {board[0][0]} | {board[0][1]} | {board[0][2]} ')
    print('-----------')
    print(f' {board[1][0]} | {board[1][1]} | {board[1][2]} ')
    print('-----------')
    print(f' {board[2][0]} | {board[2][1]} | {board[2][2]} ')

# define a function to determine the winner
def winner(player):
    # check rows
    for row in range(3):
        if board[row][0] == player and board[row][1] == player and board[row][2] == player:
            return True
    # check columns
    for col in range(3):
        if board[0][col] == player and board[1][col] == player and board[2][col] == player:
            return True
    # check diagonals
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    # if no winning combination was found, return False
    return False

# define a function to determine if the game is a draw
def draw():
    # check if there are any empty spaces on the board
    for row in range(3):
        for col in range(3):
            if board[row][col] == ' ':
                return False
    # if no empty spaces were found, return True
    return True

# define a function to make a move
def make_move(player, row, col):
    # check if the specified space is empty
    if board[row][col] == ' ':
        # make the move
        board[row][col] = player
        return True
    # if the space is not empty, return False
    return False

# define a function to determine the best move for the given player
def minimax(player):
    # check if the given player has won
    if winner(player):
        if player == X:
            return 1
        else:
            return -1
    # check if the game is a draw
    if draw():
        return 0
    # initialize the best score and best move variables
    best_score = None
