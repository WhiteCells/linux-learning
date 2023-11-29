#app:main.o add.o sub.o mult.o div.o
#	gcc main.o add.o sub.o mult.o div.o -o app


#src=main.c add.c sub.c mult.c div.c
#target=app

#$(target):$(src)
#	$(CC) $(src) -o app



# src=main.o add.o sub.o mult.o div.o
# target=app

# $(target):$(src)
# 		$(CC) $(src) -o $@

# main.o:main.c
# 		$(CC) -c $< -o $@

# add.o:add.c
# 		$(CC) -c $< -o $@

# sub.o:sub.c
# 		$(CC) -c $< -o $@

# mult.o:mult.c
# 		$(CC) -c $< -o $@

# div.o:div.c
# 		$(CC) -c $< -o $@

#src=main.o add.o sub.o mult.o div.o
#target=app

#$(target):$(src)
#	$(CC) $(src) -o $@

#%.o:%.c
#	$(CC) -c $< -o $@


src=$(wildcard ./*.c)
objs=$(patsubst %.c, %.o, $(src))
target=app

$(target):$(objs)
	$(CC) $(objs) -o $@

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm $(objs) -f
