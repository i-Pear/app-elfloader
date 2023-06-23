WITH_ZYDIS      ?= n
WITH_LWIP       ?= y
WITH_TLSF       ?= n
WITH_MUSL       ?= n
WITH_NEWLIB     ?= n

UK_ROOT  ?= /root/unikraft/unikraft
UK_LIBS  ?= /root/unikraft/libs
UK_PLATS ?= /root/unikraft/plats

LIBS-y                  := $(UK_LIBS)/lib-libelf
LIBS-$(WITH_ZYDIS)      := $(LIBS-y):$(UK_LIBS)/zydis
LIBS-$(WITH_LWIP)       := $(LIBS-y):$(UK_LIBS)/lib-lwip
LIBS-$(WITH_TLSF)       := $(LIBS-y):$(UK_LIBS)/tlsf
LIBS-$(WITH_MUSL)       := $(LIBS-y):$(UK_LIBS)/lib-musl
LIBS-$(WITH_NEWLIB)     := $(LIBS-y):$(UK_LIBS)/newlib
PLATS-y                 :=

all:
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS-y) P=$(PLATS-y)

$(MAKECMDGOALS):
	@$(MAKE) -C $(UK_ROOT) A=$(PWD) L=$(LIBS-y) P=$(PLATS-y) $(MAKECMDGOALS)
