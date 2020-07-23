#ifndef CUBIQUITY_DEMO_H_E38EB3A1
#define CUBIQUITY_DEMO_H_E38EB3A1

#include "window.h"
#include "camera.h"
#include "storage.h"

#include "flags.h"

class Demo : public Window
{
public:

	Demo(int argc, char** argv, WindowType windowType);

	const Camera& camera() { return mCamera; }
	const Cubiquity::Volume& volume() { return mVolume; }

protected:

	// Note that these overridden functions do not need to call the base class (Window) versions
	// because those don't do anything. However, classes derived from this class (Demo) *do* need
	// to explicitly call the base class (Demo) versions to obtain e.g. input handling. In C++ it is
	// complicated to automatically call base class implementations across a multi-level hierarchy
	// so we just do it manually. See e.g. https://stackoverflow.com/a/8706604
	void onInitialise() override;
	void onUpdate(float deltaTime) override;

	void onKeyUp(const SDL_KeyboardEvent& event) override;
	void onMouseButtonDown(const SDL_MouseButtonEvent& event) override;
	void onMouseButtonUp(const SDL_MouseButtonEvent& event) override;
	void onMouseMotion(const SDL_MouseMotionEvent& event) override;

	// Derived classes don't need to call the base implementations of these as they are empty.
	virtual void onCameraModified() {}
	virtual void onVolumeModified() {}

private:

	const float CameraMoveSpeed = 500.0f; // units per second
	const float CameraTurnSpeed = 0.005f;

	Camera mCamera;
	Cubiquity::Volume mVolume;

	flags::args mArgs; // Command line parsing
};

#endif // CUBIQUITY_DEMO_H_E38EB3A1
