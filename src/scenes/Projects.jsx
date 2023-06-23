import LineGradient from "../components/LineGradient";
import { motion } from "framer-motion";

const container = {
  hidden: {},
  visible: {
    transition: {
      staggerChildren: 0.2,
    },
  },
};

const projectVariant = {
  hidden: { opacity: 0, scale: 0.8 },
  visible: { opacity: 1, scale: 1 },
};

const Project = ({ title, desc, link, displayedTitle }) => {
  const overlayStyles = `absolute h-full w-full opacity-0 hover:opacity-90 transition duration-500
    bg-grey z-30 flex flex-col justify-center items-center text-center p-16 text-deep-blue`;
  const projectTitle = title.split(" ").join("-").toLowerCase();

  return (
    <motion.div variants={projectVariant} className="relative w-32 md:w-64 h-32 md:h-60">
      <div className={overlayStyles}>
        <p className="text-2xl font-playfair">{displayedTitle}</p>
        <p className="mt-7">
          {desc}
        </p>
        <a href={link} target="_blank" rel="noreferrer" className="underline bg-gray-400 p-1 rounded-md">Check it out!</a>
      </div>
      
      <img className="w-32 md:w-64 h-32 md:h-60" src={`/assets/${projectTitle}.png`} alt={projectTitle} />
    </motion.div>
  );
};

const Projects = () => {
  return (
    <section id="projects" className="pt-48 pb-48">
      {/* HEADINGS */}
      <motion.div
        className="md:w-2/5 mx-auto text-center"
        initial="hidden"
        whileInView="visible"
        viewport={{ once: true, amount: 0.5 }}
        transition={{ duration: 0.5 }}
        variants={{
          hidden: { opacity: 0, y: -50 },
          visible: { opacity: 1, y: 0 },
        }}
      >
        <div>
          <p className="font-playfair font-semibold text-4xl">
            <span className="text-red">PRO</span>JECTS
          </p>
          <div className="flex justify-center mt-5">
            <LineGradient width="w-2/3" />
          </div>
        </div>
        <p className="mt-10 mb-10">
          Some of my work
        </p>
      </motion.div>

      {/* PROJECTS */}
      <div className="flex justify-center">
        <motion.div
          className="flex flex-wrap gap-16"
          variants={container}
          // initial="visible"
          whileInView="visible"
          viewport={{ once: true, amount: 0.2 }}
        >
          <Project title={"Project 1"} displayedTitle={"Match With Spongebob"} link={"https://match-with-spongebob.netlify.app/"}/>
          <Project title={"Project 2"} displayedTitle={"Youtube Clone"} link={"https://youtube-react-js-clone.netlify.app/"}/>
          <Project title={"Project 3"} displayedTitle={"Local Git Commits Visualizer"} link={"https://github.com/abdullah-alaadine/local-git-contributions-visualizer/"}/>
          <Project title={"Project 4"} displayedTitle={"Password Generator"} link={"https://github.com/abdullah-alaadine/password-generator/"}/>
        </motion.div>
      </div>
    </section>
  );
};

export default Projects;
