template <typename R, typename ...Ts>
R Call(size_t dwMyFuncOffset, Ts... args) {
	return reinterpret_cast<R(__cdecl*)(Ts...)>(dwMyFuncOffset)(args...);
}

template <typename T, typename R, typename ...Ts>
R ThisCall(size_t dwMyFuncOffset, T* this_, Ts... args) {
	return reinterpret_cast<R(__thiscall*)(T*, Ts...)>(dwMyFuncOffset)(this_, args...);
}

template <typename T, uintptr_t Address>
class MemoryPtr {
public:
	operator T& () const {
		return **reinterpret_cast<T**>(Address);
	}

	T* operator&() const {
		return *reinterpret_cast<T**>(Address);
	}

	T* operator->() const {
		return *reinterpret_cast<T**>(Address);
	}
};

template <typename T, uintptr_t Address>
class MemoryRef {
public:
	operator T& () const {
		return *reinterpret_cast<T*>(Address);
	}

	T* operator&() const {
		return reinterpret_cast<T*>(Address);
	}

	T* operator->() const {
		return reinterpret_cast<T*>(Address);
	}
};