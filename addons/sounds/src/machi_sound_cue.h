#ifndef MACHI_SOUND_CUE_H
#define MACHI_SOUND_CUE_H

#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class MachiSoundCue : public Resource {
	GDCLASS(MachiSoundCue, Resource);

private:
	Ref<AudioStream> stream;
	int max_instances;
	float cooldown;

protected:
	static void _bind_methods();

public:
	MachiSoundCue();
	~MachiSoundCue();

	void set_stream(const Ref<AudioStream> &p_stream);
	Ref<AudioStream> get_stream() const;

	void set_max_instances(int p_max);
	int get_max_instances() const;

	void set_cooldown(float p_cooldown);
	float get_cooldown() const;
};

#endif // MACHI_SOUND_CUE_H
