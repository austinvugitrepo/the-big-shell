FROM gcc:trixie

WORKDIR /home

COPY . .

RUN gcc -o bigsh define.c external_cmd.c history.c shell.c tokenizer.c

CMD ["./bigsh"]
