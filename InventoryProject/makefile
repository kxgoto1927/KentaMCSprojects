JCC = javac
JFLAGS = -g

default: Inventory.class
	java Inventory

Inventory.class: Inventory.java
	$(JCC) $(JFLAGS) Inventory.java

clean:
	$(RM) *.class
