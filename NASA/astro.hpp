class Astro {
private:
	std::string name;
	std::vector<Astro> astro;
	void copy(const Squad& other);

public:
	//rule of 5

	Astro(std::string name);
	Astro(std::string name, std::vector<Astro> astro);
	Astro(const Astro& other);
	~Astro();
	Astro& operator=(const Astro& other);
	//getur
	std::string getName() const;
	std::vector<Astro> getAstro() const;
	int Height() const;
	int Weight() const;
	int YearsExperience() const;
