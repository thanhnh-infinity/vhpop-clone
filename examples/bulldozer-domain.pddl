; Bulldozer domain used in (Nguyen & Kambhampati 2001)

(define (domain bulldozer)
  (:predicates (road ?from ?to)
	       (at ?thing ?place)
	       (mobile ?thing)
	       (bridge ?from ?to)
	       (person ?p)
	       (vehicle ?v)
	       (driving ?p ?v))
  (:action drive
	   :parameters (?thing ?from ?to)
	   :precondition (and (road ?from ?to)
			      (at ?thing ?from)
			      (mobile ?thing))
	   :effect (and (at ?thing ?to) (not (at ?thing ?from))))
  (:action cross
	   :parameters (?thing ?from ?to)
	   :precondition (and (bridge ?from ?to)
			      (at ?thing ?from)
			      (mobile ?thing))
	   :effect (and (at ?thing ?to) (not (at ?thing ?from))))
  (:action board
	   :parameters (?person ?place ?vehicle)
	   :precondition (and (at ?person ?place)
			      (person ?person)
			      (vehicle ?vehicle)
			      (at ?vehicle ?place))
	   :effect (and (driving ?person ?vehicle)
			(mobile ?vehicle)
			(not (at ?person ?place))
			(not (mobile ?person))))  
  (:action disembark
	   :parameters (?person ?place ?vehicle)
	   :precondition (and (person ?person)
			      (vehicle ?vehicle)
			      (driving ?person ?vehicle)
			      (at ?vehicle ?place))
	   :effect (and (at ?person ?place)
			(mobile ?person)
			(not (driving ?person ?vehicle))
			(not (mobile ?vehicle)))))
