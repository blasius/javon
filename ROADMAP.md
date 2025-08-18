# Javon Roadmap – Early Stage

This roadmap outlines the first tasks and milestones for contributors to the Javon programming language project. The goal is to make the language tangible and community-driven while focusing on small, actionable tasks.

---

## 1️⃣ Language Specification
- [ ] Draft **basic syntax** for variables, functions, and classes.
- [ ] Define **primitive types** (int, float, boolean, string).
- [ ] Outline **class and method declaration rules**.
- [ ] Write a simple **type system draft** (static typing rules).
- [ ] Document all the above in `docs/syntax.md`.

---

## 2️⃣ Parser & AST
- [ ] Implement a **basic lexer** to convert source code into tokens.
- [ ] Define **AST node structures** for expressions, statements, and classes.
- [ ] Write a **parser** that converts tokens into an AST.
- [ ] Test parser on very simple programs (e.g., variable assignment, arithmetic).
- [ ] Add **unit tests** for lexer and parser in `tests/`.

---

## 3️⃣ Prototype Interpreter
- [ ] Implement a **simple interpreter** for expressions and basic statements.
- [ ] Test evaluation of arithmetic operations, variable assignment, and print statements.
- [ ] Ensure interpreter produces expected output for sample programs in `examples/`.

---

## 4️⃣ Example Programs
- [ ] “Hello World” program.
- [ ] Simple class with one method.
- [ ] Program with basic arithmetic and conditionals.
- [ ] Place all examples in `examples/` folder with clear comments.

---

## 5️⃣ Documentation & Contributor Support
- [ ] Create `CONTRIBUTING.md` with guidelines for submitting ideas, PRs, and tests.
- [ ] Keep `README.md` roadmap updated with active tasks.
- [ ] Add **diagrams** or charts explaining AST and language flow (optional, helpful for newcomers).

---

## 6️⃣ Project Infrastructure
- [ ] Set up **basic folder structure** (`src/`, `docs/`, `tests/`, `examples/`).
- [ ] Add **scripts/** for running parser/interpreter prototypes.
- [ ] Configure **GitHub issue templates** for features, bugs, and experiments.

---

💡 **Key Principles for Early Stage:**
- Focus on **small, verifiable tasks** that make the language tangible.
- Every contribution should either **improve the design**, **add parsing/interpreting capability**, or **enhance documentation**.
- Avoid worrying about full compilation, optimization, or standard library at this stage.
