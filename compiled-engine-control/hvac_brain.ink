# We define the states and their type. In this case, Float values.
inkling "2.0"
using Number
type State {
    Tset: Number.Float32,
    Tin: Number.Float32,
    #Tset1: Number.Float32,
    #Tset2: Number.Float32,
    #Tset3: Number.Float32,
    #Tdiff: Number.Float32
}

# We define actions and their type. In this case, integer values constrained to 0 or 1
type Action {
    hvacON: Number.Float32<0,1>
    #hvacON: Number.Float32<0,0.25,0.5,0.75,1>
    #hvacON: Number.Float32<0..1>
}

# We define a simulator configuration variable that can be used 
# to dynamically alter the simulator parameters during training (ex: house conductivity K)
# in the example below we don't use it but still define it.
type SimulatorConfig {
    dummy: Number.Int8
}

# We declare the simulator's name and it's dependencies
# the simulator name must match the class name declared in hub.py in Model_Connector.
simulator the_simulator(action: Action, config: SimulatorConfig): State {
}

graph (input: State): Action {

    # We declare and name a concept that we want to teach, define it's type 
    # (ex: classifier for discrete values or estimator for continuous values)
    concept AnjiansHvac(input): Action {
        curriculum {
            source the_simulator
            lesson my_first_lesson {
                constraint {
                    dummy: -1
                }
            }
        }
    }
    output AnjiansHvac
}
