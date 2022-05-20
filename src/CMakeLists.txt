# CMakeList.txt : CMake project for ex3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
target_sources (mario_project PRIVATE "main.cpp"
                                      "Controller.cpp"
                                      "Game.cpp"
                                      "Board.cpp"
                                      "Block.cpp"
                                      "Player.cpp"
                                      "Enemy.cpp"
                                      "IdleObject.cpp"
                                      "MovingObject.cpp"
                                      "Sound.cpp"
                                      "Sprite.cpp"
                                      "AnimatedSprite.cpp"
                                      "AudioController.cpp"
                                      "MainMenu.cpp"
                                      "GoompaO.cpp"
                                      "GoompaB.cpp"
                                      "Turtle.cpp"
                                      "Coin.cpp"
                                      "Grass.cpp"
                                      "Question.cpp"
                                      "Trampoline.cpp")

# TODO: Add tests and install targets if needed.
