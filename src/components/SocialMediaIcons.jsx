const SocialMediaIcons = () => {
  return (
    <div className="flex justify-center md:justify-start my-10 gap-7">
      <a
        className="hover:opacity-50 transition duration-500"
        href="https://www.linkedin.com/in/abdullah-alaadine/"
        target="_blank"
        rel="noreferrer"
      >
        <img alt="linkedin-link" src="src/assets/linkedin.png" />
      </a>
      <a
        className="hover:opacity-50 w-8 bg-white rounded-sm transition duration-500"
        href="https://github.com/abdullah-alaadine/"
        target="_blank"
        rel="noreferrer"
      >
        <img alt="github-link" src="src/assets/github.png" />
      </a>
    </div>
  );
};

export default SocialMediaIcons;
