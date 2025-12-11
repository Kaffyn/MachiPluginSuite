#ifndef SOUND_CUE_H
#define SOUND_CUE_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/templates/vector.hpp>

using namespace godot;

class SoundCue : public Resource {
	GDCLASS(SoundCue, Resource);

private:
	TypedArray<AudioStream> audio_streams;
	float pitch_min = 1.0f;
	float pitch_max = 1.0f;
	float volume_min_db = 0.0f;
	float volume_max_db = 0.0f;
    bool is_sequence = false;
    int _last_index = -1;

protected:
	static void _bind_methods();

public:
	void set_audio_streams(const TypedArray<AudioStream> &p_streams);
	TypedArray<AudioStream> get_audio_streams() const;

	void set_pitch_min(float p_pitch);
	float get_pitch_min() const;

	void set_pitch_max(float p_pitch);
	float get_pitch_max() const;

	void set_volume_min_db(float p_volume_db);
	float get_volume_min_db() const;

	void set_volume_max_db(float p_volume_db);
	float get_volume_max_db() const;
    
    void set_is_sequence(bool p_sequence);
    bool get_is_sequence() const;

    // Helper to get a stream (random or sequential)
    Ref<AudioStream> get_next_stream();
    float get_next_pitch() const;
    float get_next_volume() const;
};

#endif // SOUND_CUE_H
