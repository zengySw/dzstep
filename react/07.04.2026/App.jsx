import React, { useRef } from 'react';
import './App.css';

const App = () => {
  const nameRef = useRef(null);
  const emailRef = useRef(null);
  const passwordRef = useRef(null);

  const handleSubmit = (event) => {
    event.preventDefault();

    const name = nameRef.current.value.trim();
    const email = emailRef.current.value.trim();
    const password = passwordRef.current.value;

    if (!name) {
      nameRef.current.focus();
      return;
    }

    if (!email) {
      emailRef.current.focus();
      return;
    }

    if (password.length < 6) {
      alert('Пароль должен быть не короче 6 символов.');
      return;
    }

    alert(`Данные формы:\nИмя: ${name}\nEmail: ${email}\nПароль: ${password}`);
  };

  return (
    <main className="form-page">
      <section className="form-card">
        <h1>Форма с useRef</h1>
        <p>Заполните поля и нажмите «Отправить».</p>

        <form className="user-form" onSubmit={handleSubmit} noValidate>
          <label htmlFor="name">Имя</label>
          <input id="name" type="text" ref={nameRef} placeholder="Введите имя" />

          <label htmlFor="email">Email</label>
          <input id="email" type="email" ref={emailRef} placeholder="Введите email" />

          <label htmlFor="password">Пароль</label>
          <input
            id="password"
            type="password"
            ref={passwordRef}
            placeholder="Минимум 6 символов"
          />

          <button type="submit">Отправить</button>
        </form>
      </section>
    </main>
  );
};

export default App;
