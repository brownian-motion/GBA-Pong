default: target/main.gba

.PHONY: default image clean

target/main.gba: src/* image
	mkdir -p target
	sudo docker run \
		-w /src --read-only --mount type=bind,source=${CURDIR}/src,target=/src \
		--mount type=bind,source=${CURDIR}/target,target=/target \
		devkitarm:latest bash -c " \
			arm-none-eabi-gcc -c main.c -mthumb-interwork -mthumb -O2 -o /target/main.o ; \
			arm-none-eabi-gcc /target/main.o -mthumb-interwork -mthumb -specs=gba.specs -o /target/main.elf ; \
			arm-none-eabi-objcopy -v -O binary /target/main.elf /target/main.gba ; \
			gbafix /target/main.gba \
		"

image: build.Dockerfile
	sudo docker build -t devkitarm:latest -f build.Dockerfile .

#NOTE: only seems to work on Linux
clean:	
	$(RM) -rf target