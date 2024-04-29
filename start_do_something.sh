#!/bin/bash


cd grep
make s21_grep

valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./
