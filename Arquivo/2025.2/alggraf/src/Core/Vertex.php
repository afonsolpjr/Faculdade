<?php

namespace AlgGraph\Core;

#[\AllowDynamicProperties]
class Vertex {
	
    public mixed $label; 
    public mixed $value;  
    public array $neighbors;

	public int $degree;

    public function __construct($label, mixed $value = null) {
        $this->label = $label;
        $this->value = $value;
		$this->degree = 0;
    }

	public function add_neighbor(Vertex $v)
	{
		$this->neighbors[] = $v;
		$this->degree++;
	}

	public function print_neighbors()
	{
		printf("Vizinhos de V%d : [",$this->label);
		foreach ($this->neighbors as $neighbor) {
			printf("%d,",$neighbor->label);	
		}
		echo "]\n";
	}
}
