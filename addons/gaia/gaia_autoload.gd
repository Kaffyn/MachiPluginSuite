extends MachiGaia

# This script exists just to be loaded as an Autoload.
# It inherits the C++ implementation directly.

## Helper to setup 3D environment connections
func setup_3d(environment: WorldEnvironment, sun: DirectionalLight3D) -> void:
    if environment:
        register_sky(environment)
    if sun:
        register_sun(sun)
