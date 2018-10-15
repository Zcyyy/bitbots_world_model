#ifndef MOVEMENTMODELS
#define MOVEMENTMODELS

#include <memory>

#include <libPF/MovementModel.h>
#include <bitbots_world_model/ObstacleStates.h>
// #include <libPF/CRandomNumberGenerator.h>

/**
 * @class MyMovementModel
 *
 * @brief Test class for ParticleFilter.
 *
 * This simple movement model only adds a small jitter in diffuse() and does
 * nothing in drift().
 * @author Stephan Wirth
 */
class LocalObstacleMovementModel : public libPF::MovementModel<ObstacleStateW> {

  public:
    /**
     * empty
     */
    LocalObstacleMovementModel(libPF::CRandomNumberGenerator& random_number_generator, double xStdDev, double yStdDev, double multiplicator);

    /**
     * empty
     */
    ~LocalObstacleMovementModel();

    /**
     * The drift method is empty in this example.
     * @param state Pointer to the state that has to be manipulated.
     */
    void drift(ObstacleStateW& state, double dt) const;

    /**
     * The diffusion consists of a very small gaussian jitter on the
     * state's variable.
     * @param state Pointer to the state that has to be manipulated.
     */
    void diffuse(ObstacleStateW& state, double dt) const;

  protected:

  private:

    // The random number generator
    libPF::CRandomNumberGenerator random_number_generator_;

    // standard deviations and multiplicator for the diffuse step
    double xStdDev_, yStdDev_, multiplicator_;

};

#endif
