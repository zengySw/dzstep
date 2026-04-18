import { render, screen } from '@testing-library/react';
import App from './App';

test('renders form fields and submit button', () => {
  render(<App />);

  expect(screen.getByLabelText(/user id/i)).toBeInTheDocument();
  expect(screen.getByLabelText(/password/i)).toBeInTheDocument();
  expect(screen.getByRole('button', { name: /submit/i })).toBeInTheDocument();
});
